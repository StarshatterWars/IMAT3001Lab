// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "../ShooterGameInstance.h"
#include "W_MainMenu.generated.h"

/**
 *
 */
UCLASS()
class UW_MainMenu : public UUserWidget
{
	GENERATED_BODY()

		UPROPERTY(meta = (BindWidgetOptional))
		class UTextBlock* GameTitleText;

public:
	UFUNCTION(BlueprintCallable, Category = "Game Info")
		void ShowGameInfo();
	UFUNCTION(BlueprintCallable, Category = "Game Info")
		UShooterGameInstance* GetShooterGameInstance();


};
