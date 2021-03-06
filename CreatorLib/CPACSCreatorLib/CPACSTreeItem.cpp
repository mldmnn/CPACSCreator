/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
//
// Created by cfse on 3/13/18.
//

#include "CPACSTreeItem.h"
#include <iostream>

#include "UniqueXPath.h"
#include "CPACSTree.h"
#include "easylogging++.h"

namespace cpcr {


    CPACSTreeItem::CPACSTreeItem() {
        this->tixiIdx = -1;
        this->type = "";
        this->parent = nullptr;
        this->xpath = UniqueXPath();
        this->tree = nullptr;
        this->children = std::vector<CPACSTreeItem*>() ;
        this->uid = "";
    }

    CPACSTreeItem::CPACSTreeItem(CPACSTree* tree, UniqueXPath xpath, std::string cpacsType, int tixiIndex, std::string uid ) {
        this->tixiIdx = tixiIndex;
        this->type = cpacsType;
        this->parent = nullptr;
        this->xpath = xpath;
        this->tree = tree;
        this->children = std::vector<CPACSTreeItem*>() ;
        this->uid = uid;

    }

    CPACSTreeItem::~CPACSTreeItem() {
        //recursive call of destructor
        for (std::vector<CPACSTreeItem *>::iterator it = children.begin(); it != children.end(); ++it) {
            //std::string ref =  (*it)->toString();
            delete (*it);
            //LOG(INFO) << "Deleted: " + ref;
        }
        children.clear();
    }

    CPACSTreeItem *CPACSTreeItem::addChild(UniqueXPath xpath, std::string cpacsType, int tixiIndex, std::string uid ) {

        CPACSTreeItem *newChild = new CPACSTreeItem(this->tree, xpath, cpacsType, tixiIndex, uid );
        newChild->parent = this;
        children.push_back(newChild);
        return newChild;
    }

    CPACSTreeItem *CPACSTreeItem::getParent() const {
        return parent;
    };

    std::vector<CPACSTreeItem *> CPACSTreeItem::getChildren() const {
        return children;
    };

    int CPACSTreeItem::getTixiIndex() const {
        return tixiIdx;
    }

    std::string CPACSTreeItem::getType() const {
        return type;
    }

    UniqueXPath CPACSTreeItem::getXPath() const {
        return xpath;
    }


    // todo: test this function
    int CPACSTreeItem::positionRelativelyToParent() const {

        int position = -1;
        CPACSTreeItem *parent = getParent();

        if (parent != nullptr) {
            for(int i = 0; i < parent->getChildren().size(); i++ ){
                if(parent->getChildren()[i] == this){
                    position = i;
                }
            }
        }
        return position;
    }

    bool CPACSTreeItem::hasChildOfType(std::string type) {
        for (std::vector<CPACSTreeItem *>::iterator it = children.begin(); it != children.end(); ++it) {
            if((*it)->getType() == type ) return true;
        }
        return false;
    }


    // todo clarify the xpath (for the moment the first element is taken )
    CPACSTreeItem *CPACSTreeItem::getChild(UniqueXPath xpath, bool warnings) {

        CPACSTreeItem* r =  nullptr;

        std::string type =  xpath.getFirstElementType();
        int index = xpath.getFirstElementIndex();
        std::string first = xpath.popFirst();

        if(first == "." ){
            type = xpath.getFirstElementType();
            index = xpath.getLastElementIndex();
            first = xpath.popFirst();

        }

        std::vector<CPACSTreeItem *>::iterator it = children.begin();
        while( r == nullptr && it != children.end()) {
            if((*it)->getType() == type && (*it)->getTixiIndex() == index ){
               r = *it;
            }
            it++;
        }

        if( r == nullptr && warnings){
            LOG(ERROR) << "xpath: \"" + xpath.toString() + "\" not valid!"  ;
            return r;
        }

        if( ! xpath.isEmpty() ){
            r = r->getChild(xpath);
        }

        return r;
    }


    CPACSTree *CPACSTreeItem::getTree() const {
        return tree;
    }

    std::vector<CPACSTreeItem *> CPACSTreeItem::findAllChildrenOfTypeRecursively(std::string type) {

        std::vector<CPACSTreeItem*> r;

        for( auto p : children ){   // acces by value -> so it's a pointer to CPACSTreeItem object
           std::vector<CPACSTreeItem*> temp = p->findAllChildrenOfTypeRecursively(type);
           r.insert(r.end(), temp.begin(), temp.end());
           if(p->getType() == type ){
               r.push_back(p);
           }
        }

        return r;
    }

    CPACSTreeItem *CPACSTreeItem::getChildByUid(std::string searchedUid) {


        // if we have a children with the researched Uid we return
        for(auto p : children) {
            if (p->getUid() == searchedUid){
                return p;
            }
        }

        // other wise we continue to search
        CPACSTreeItem * r = nullptr;
        if( r == nullptr ){
            for(auto p: children ){
                r = p->getChildByUid(searchedUid);
                if(r != nullptr) return r;
            }
        }

        return r;

    }

    CPACSTreeItem* CPACSTreeItem::getChild(std::string xpathString, bool warnings) {
        return getChild(UniqueXPath(xpathString), warnings);
    }

    CPACSTreeItem *CPACSTreeItem::getParentOfType(std::string type, bool withoutWarning ) {

        CPACSTreeItem * parent = this->getParent();
        if( parent == nullptr) {
            if( ! withoutWarning){
                LOG(WARNING) << "The parent of the required type \"" << type << " \" was not found.";
            }
            return nullptr;
        }
        if( parent->getType() == type ){
            return parent;
        }

        // else recursive call
        return parent->getParentOfType(type, withoutWarning);
    }

    bool CPACSTreeItem::hasParentOfType(std::string type) {
        if (getParentOfType(type, true) != nullptr){
            return true;
        }
        return false;
    }


}



