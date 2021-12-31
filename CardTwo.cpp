#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& cellposition) : Card(cellposition) {
	cardNumber = 2;
}

void CardTwo::Apply(Grid* pGrid,Player* pPlayer) {
	Output* pOut = pGrid->GetOutput();
	Ladder* P = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
		pGrid->PrintErrorMessage("You've reached card 2 !  moving to the next ladder, click anywhere to continue...");
	if (P)
	{
		pGrid->UpdatePlayerCell(pPlayer, P->GetPosition());
	}
	else pOut->PrintMessage("No ladders ahead....");
 }