#pragma once

#include<iostream>
#include<cocos2d.h>
USING_NS_CC;
class AnimationCreator
{
public:
	AnimationCreator();
	~AnimationCreator();
	// ����Ϊ���ļ�����ͼƬ������ÿһ֡���ż��ʱ�䣬���Ŵ���
	static Animation* createAnimWithFrameNameAndNum(const char* name,int num,float delay,unsigned int loops);
};

