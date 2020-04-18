#include "XgPixelTestBed.h"

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

XgPixelTestBed::XgPixelTestBed()
{
}


XgPixelTestBed::~XgPixelTestBed()
{
}

XgPaper *XgPixelTestBed::CharacterAttack()
{
	std::string MOVE_STATE = "MOVE";
	std::string TURN_STATE = "TURN";
	std::string IDLE_STATE = "IDLE";

	XgFlipBook *attackFlipBook = new XgFlipBook(30.0f);
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

	XgFlipBook *idleFlipBook = new XgFlipBook(30.0f);
	idleFlipBook->setScale(0.5f, 0.8f);
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

	XgState *moveState = new XgState(MOVE_STATE);
	moveState->add(new XgEventKeyboard(TURN_STATE, 'T'));
	moveState->add(new XgEventKeyboard(IDLE_STATE, 'I'));
	moveState->add(new XgActionChangeAnimation(attackFlipBook));
	moveState->add(new XgActionSetDirection(1.0, 0.0, 0.0));
	moveState->add(new XgActionMove(0.01f));

	XgState *turnState = new XgState(TURN_STATE);
	turnState->add(new XgEventGoto(MOVE_STATE));
	turnState->add(new XgActionNegDirection());
	turnState->add(new XgActionSpin(0.0, 180.0, 0.0));

	XgState *idleState = new XgState(IDLE_STATE);
	idleState->add(new XgActionChangeAnimation(idleFlipBook));
	idleState->add(new XgEventKeyboard(MOVE_STATE, 'M'));

	XgFramework *framework = new XgFramework();
	framework->add(moveState);
	framework->add(turnState);
	framework->add(idleState);

	XgCharacter *character = new XgCharacter();
	character->add(framework);
	character->add(attackFlipBook);
	character->add(idleFlipBook);

	XgPaper *paper = new XgPaper();

	paper->add(character);

	return(paper);
}
