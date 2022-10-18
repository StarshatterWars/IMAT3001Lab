// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/GameInstance.h"
#include "ShooterGameInstance.generated.h"

/**
 *
 */
UCLASS()
class IMAT3001A_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UShooterGameInstance(const FObjectInitializer& ObjectInitializer);

	void InitializeMainMenuScreen(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Game Init")
		void GameInit();

	UFUNCTION(BlueprintCallable, Category = "Widgets")
		void ShowMainMenu();

private:
	TSubclassOf<class UW_MainMenu> MainMenuWidgetClass;
};
