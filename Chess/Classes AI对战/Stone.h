#ifndef Stone_H
#define Stone_H

#include "cocos2d.h"

USING_NS_CC;

#define stone_def_x 70
#define stone_def_y 35
#define stone_def   64

class Stone : public Sprite
{
public:
	enum TYPE { JIANG, SHI, XIANG, JU, MA, PAO, BING };
	CC_SYNTHESIZE(TYPE, type, Type);
	CC_SYNTHESIZE(int, x, X);
	CC_SYNTHESIZE(int, y, Y);
	CC_SYNTHESIZE(int, id, ID);
	CC_SYNTHESIZE(bool, isDead, isDead);
	CC_SYNTHESIZE(bool, isRed, isRed);

	static Stone* create(int _id, bool _clickRed){
		Stone* stone = new Stone();
		stone->init(_id, _clickRed);
		stone->autorelease();
		return stone;
	}
	void reset(bool _clickRed);
	bool init(int _id, bool _clickRed){
		const char* stonePic[14] = {
			"res/rshuai.png",
			"res/rshi.png",
			"res/rxiang.png",
			"res/rche.png",
			"res/rma.png",
			"res/rpao.png",
			"res/rbing.png",

			"res/bjiang.png",
			"res/bshi.png",
			"res/bxiang.png",
			"res/bche.png",
			"res/bma.png",
			"res/bpao.png",
			"res/bzu.png"
		};
		id = _id;

		// �Ƿ������Ǻ��壬�͸���id��λ���޹أ�id<16�ľ������°벿��
		if (id < 16){
			type = stonePoints[id].type;
		}
		else{
			type = stonePoints[id - 16].type;
		}
		int iconIndex = -1;

		if (_clickRed){
			// ���������Ǻ���,id<16�Ķ�����Ҫ������Դ
			iconIndex = (id < 16 ? 0 : 1) * 7 + type;
			isRed = id < 16;
		}
		else{
			// ���������Ǻ���,id<16�Ķ�����Ҫ������Դ
			iconIndex = (id < 16 ? 1 : 0) * 7 + type;
			isRed = id >= 16;
		}
		Sprite::initWithFile(stonePic[iconIndex]);
		//setScale(0.6f);
		reset(_clickRed);
		return true;
	}
	static struct StoneInitPoint{
		int x;
		int y;
		Stone::TYPE type;
	}
	stonePoints[32];
	int getRealX();
	int getRealY();
};


#endif
