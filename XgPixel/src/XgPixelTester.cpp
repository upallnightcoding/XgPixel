// XgPixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "XgPixel.h"
#include "XgSprite.h"
#include "XgActionMove.h"
#include "XgActionSetDirection.h"
#include "XgEventGoto.h"
#include "XgActionNegDirection.h"
#include "XgActionSpin.h"
#include "XgEventKeyboard.h"
#include "XgFlipBook.h"
#include "XgActionChangeAnimation.h"

int main()
{
	std::string MOVE_STATE = "MOVE";
	std::string TURN_STATE = "TURN";
	std::string IDLE_STATE = "IDLE";

	XgState *moveState = new XgState(MOVE_STATE);
	moveState->add(new XgEventKeyboard(TURN_STATE, 'T'));
	moveState->add(new XgEventKeyboard(IDLE_STATE, 'I'));
	moveState->add(new XgActionSetDirection(1.0, 0.0, 0.0));
	moveState->add(new XgActionMove(0.0, 0.0, 0.0));

	XgState *turnState = new XgState(TURN_STATE);
	turnState->add(new XgEventGoto(MOVE_STATE));
	turnState->add(new XgActionNegDirection());
	turnState->add(new XgActionSpin(0.0, 180.0, 0.0));

	XgState *idleState = new XgState(IDLE_STATE);
	idleState->add(new XgActionChangeAnimation(1));
	
	XgFramework *framework = new XgFramework();
	framework->add(moveState);
	framework->add(turnState);
	framework->add(idleState);

	XgFlipBook *attackFlipBook = new XgFlipBook();
	attackFlipBook->add(new XgSprite("Attack__000.png"));
	attackFlipBook->add(new XgSprite("Attack__001.png"));
	attackFlipBook->add(new XgSprite("Attack__002.png"));
	attackFlipBook->add(new XgSprite("Attack__003.png"));
	attackFlipBook->add(new XgSprite("Attack__004.png"));
	attackFlipBook->add(new XgSprite("Attack__005.png"));
	attackFlipBook->add(new XgSprite("Attack__006.png"));
	attackFlipBook->add(new XgSprite("Attack__007.png"));
	attackFlipBook->add(new XgSprite("Attack__008.png"));
	attackFlipBook->add(new XgSprite("Attack__009.png"));

	XgFlipBook *idleFlipBook = new XgFlipBook();
	idleFlipBook->add(new XgSprite("Idle__000.png"));
	idleFlipBook->add(new XgSprite("Idle__001.png"));
	idleFlipBook->add(new XgSprite("Idle__002.png"));
	idleFlipBook->add(new XgSprite("Idle__003.png"));
	idleFlipBook->add(new XgSprite("Idle__004.png"));
	idleFlipBook->add(new XgSprite("Idle__005.png"));
	idleFlipBook->add(new XgSprite("Idle__006.png"));
	idleFlipBook->add(new XgSprite("Idle__007.png"));
	idleFlipBook->add(new XgSprite("Idle__008.png"));
	idleFlipBook->add(new XgSprite("Idle__009.png"));

	//XgSprite *sprite = new XgSprite("Attack__000.png");
	//sprite->add(framework);

	XgCharacter *item = new XgCharacter();
	item->fsm(framework);
	item->add(idleFlipBook);
	item->add(attackFlipBook);

	XgPixel pixel("XgPixel Test Bed", 600, 600);
	
	//sprite->add(new XgActionSetDirection(1.0, 0.0, 0.0));
	//sprite->add(new XgActionMove(0.0, 0.0, 0.0));

	XgPaper *paper = new XgPaper();

	paper->add(item);

	pixel.add(paper);

	pixel.startAnimation();
}

