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
#include "XgBackGround.h"

XgPixelTestBed::XgPixelTestBed()
{
}


XgPixelTestBed::~XgPixelTestBed()
{
}

XgPaper *XgPixelTestBed::characterIdle()
{
	std::string IDLE_STATE = "IDLE";

	XgBackGround *bg = new XgBackGround("BG.png");
	bg->setScale(5.0, 5.0);

	//XgFlipBook *idleFlipBook = new XgFlipBook(1.0f);
	XgFlipBook *idleFlipBook = new XgFlipBook(30.0f);
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

	XgState *idleState = new XgState(IDLE_STATE);
	idleState->add(new XgActionChangeAnimation(idleFlipBook));

	XgFramework *framework = new XgFramework();
	framework->add(idleState);

	XgCharacter *character = new XgCharacter();
	character->setScale(0.25f, 0.25f);
	//character->setScale(1.0f, 1.0f);
	character->add(framework);
	character->add(idleFlipBook);

	XgPaper *paper = new XgPaper();
	paper->add(character);
	//paper->add(bg);				// Background has to be last character added
	
	return(paper);
}

XgPaper *XgPixelTestBed::characterTwoIdle()
{
	std::string IDLE_STATE = "IDLE";

	XgBackGround *bg = new XgBackGround("BG.png");
	bg->setScale(5.0, 5.0);

	//XgFlipBook *idleFlipBook = new XgFlipBook(1.0f);
	XgFlipBook *idleFlipBookR = new XgFlipBook(30.0f);
	idleFlipBookR->add(new XgSprite("Idle__000.png"));
	idleFlipBookR->add(new XgSprite("Idle__001.png"));
	idleFlipBookR->add(new XgSprite("Idle__002.png"));
	idleFlipBookR->add(new XgSprite("Idle__003.png"));
	idleFlipBookR->add(new XgSprite("Idle__004.png"));
	idleFlipBookR->add(new XgSprite("Idle__005.png"));
	idleFlipBookR->add(new XgSprite("Idle__006.png"));
	idleFlipBookR->add(new XgSprite("Idle__007.png"));
	idleFlipBookR->add(new XgSprite("Idle__008.png"));
	idleFlipBookR->add(new XgSprite("Idle__009.png"));

	XgFlipBook *idleFlipBookL = new XgFlipBook(30.0f);
	idleFlipBookL->add(new XgSprite("Idle__000.png"));
	idleFlipBookL->add(new XgSprite("Idle__001.png"));
	idleFlipBookL->add(new XgSprite("Idle__002.png"));
	idleFlipBookL->add(new XgSprite("Idle__003.png"));
	idleFlipBookL->add(new XgSprite("Idle__004.png"));
	idleFlipBookL->add(new XgSprite("Idle__005.png"));
	idleFlipBookL->add(new XgSprite("Idle__006.png"));
	idleFlipBookL->add(new XgSprite("Idle__007.png"));
	idleFlipBookL->add(new XgSprite("Idle__008.png"));
	idleFlipBookL->add(new XgSprite("Idle__009.png"));

	XgState *idleStateR = new XgState(IDLE_STATE);
	idleStateR->add(new XgActionChangeAnimation(idleFlipBookR));
	idleStateR->add(new XgActionSetDirection(1.0, 0.0, 0.0));
	idleStateR->add(new XgActionMove(0.001f));

	XgState *idleStateL = new XgState(IDLE_STATE);
	idleStateL->add(new XgActionChangeAnimation(idleFlipBookL));
	idleStateL->add(new XgActionSetDirection(-1.0, 0.0, 0.0));
	idleStateL->add(new XgActionMove(0.001f));

	XgFramework *frameworkR = new XgFramework();
	frameworkR->add(idleStateR);

	XgFramework *frameworkL = new XgFramework();
	frameworkL->add(idleStateL);

	XgCharacter *characterL = new XgCharacter();
	characterL->setScale(0.25f, 0.25f);
	characterL->add(frameworkL);
	characterL->add(idleFlipBookL);

	XgCharacter *characterR = new XgCharacter();
	characterR->setScale(0.25f, 0.25f);
	characterR->add(frameworkR);
	characterR->add(idleFlipBookR);

	XgPaper *paper = new XgPaper();
	paper->add(characterR);
	paper->add(characterL);
	paper->add(bg);

	return(paper);
}

XgPaper *XgPixelTestBed::characterAttack()
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
	character->setScale(0.5f, 0.8f);
	character->add(framework);
	character->add(attackFlipBook);
	character->add(idleFlipBook);

	XgPaper *paper = new XgPaper();

	paper->add(character);

	return(paper);
}
