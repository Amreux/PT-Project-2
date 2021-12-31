#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}


bool Snake::IsOverlapping(GameObject* newObj) const {
	if (GetEndPosition().VCell() >= newObj->GetPosition().VCell() && GetPosition().VCell() <= newObj->GetPosition().VCell()) {
		return true;
	}

	Snake* pSna = dynamic_cast <Snake*> (newObj);

	if (pSna) {
		if (pSna->GetEndPosition().VCell() >= GetPosition().VCell() && pSna->GetPosition().VCell() <= GetPosition().VCell()) {
			return true;
		}

	}


	return false;

}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
