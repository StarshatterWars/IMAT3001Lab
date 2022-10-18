// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameInstance.h"
#include "Widgets/W_MainMenu.h"

UShooterGameInstance::UShooterGameInstance(const FObjectInitializer& ObjectInitializer)
{
	GameInit();
	//InitializeMainMenuScreen(ObjectInitializer);
}

void UShooterGameInstance::GameInit()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("IMAT 3001!"));
}

void UShooterGameInstance::InitializeMainMenuScreen(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UW_MainMenu> MainMenuWidget(TEXT("/Game/Gameplay/Widgets/WB_MainMenu"));
	if (!ensure(MainMenuWidget.Class != nullptr))
	{
		return;
	}
	MainMenuWidgetClass = MainMenuWidget.Class;
}

void UShooterGameInstance::ShowMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Loading Main Menu Screen"));

	// Create widget
	UW_MainMenu* MainMenuScreen = CreateWidget<UW_MainMenu>(this, MainMenuWidgetClass);
	// Add it to viewport
	MainMenuScreen->AddToViewport();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(MainMenuScreen->TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
}

