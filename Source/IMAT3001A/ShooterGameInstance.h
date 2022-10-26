// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "ShooterGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FS_PlayerDAta : public FTableRowBase
{

	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Nickname;

};

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

	UFUNCTION(BlueprintCallable, Category = "Game Data")
		void LoadGameData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
		int32 PlayerSaveIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
		FString  PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
		bool  PlayerLoaded;


private:
	TSubclassOf<class UW_MainMenu> MainMenuWidgetClass;
};
