// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/W_MainMenu.h"

void UW_MainMenu::ShowGameInfo()
{
	GameTitleText->SetText(FText::FromString("IMAT 3001 Game"));
}

UShooterGameInstance* UW_MainMenu::GetShooterGameInstance()
{
	UShooterGameInstance* inst = (UShooterGameInstance*)GetGameInstance();
	return inst;
}

