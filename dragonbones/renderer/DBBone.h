//
//  DBBone.hpp
//  dragonbones
//
//  Created by Relvin on 16/2/4.
//  Copyright © 2016年 Relvin. All rights reserved.
//

#ifndef DBBone_hpp
#define DBBone_hpp

#include "2d/CCNode.h"
#include "DragonBones.h"
#include "objects/BoneData.h"
#include "core/DBBase.h"
#include "animation/TimelineState.h"

NAME_SPACE_DRAGON_BONES_BEGIN

class DBArmature;

class DBBone
: public cocos2d::Node
, public DBBase
{
public:
    static DBBone* create(BoneData* boneData);
    bool initWithBoneData(BoneData* boneData);
    DBBone();
    virtual ~DBBone();
    
    void addChildBone(DBBone *child);
    void removeChildBone(DBBone *bone, bool recursion);
    
    void setArmature(DBArmature *armature);
    void calculateParentTransform( Transform &transform, Matrix &matrix ) override;
    
    virtual void calculateRelativeParentTransform() override;
    
    void update(float needUpdate) override;
    void blendingTimeline();
public:
    std::string displayController;
    bool applyOffsetTranslationToChild;
    bool applyOffsetRotationToChild;
    bool applyOffsetScaleToChild;
    
    Transform _globalTransformForChild;
    Matrix _globalTransformMatrixForChild;
    
    virtual const Point& getTweenPivot() const;
    int getNeedUpdate();
protected:
    cocos2d::Vector<DBBone*> _childBones;        ///< array of children nodes
//    std::vector<Slot*> _slotList;
    std::vector<TimelineState*> _timelineStateList;
    
    int _needUpdate;
    bool _isColorChanged;
    
    Point _tweenPivot;
    Transform _tween;
    
private:
    Transform _tempGlobalTransformForChild;
    Matrix _tempGlobalTransformMatrixForChild;
    BoneData* _boneData;
    
    DBArmature* _pArmature;
    
};

NAME_SPACE_DRAGON_BONES_END


#endif /* DBBone_hpp */
