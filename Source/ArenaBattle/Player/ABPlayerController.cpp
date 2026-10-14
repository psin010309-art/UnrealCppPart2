// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"
#include <UI/ABHUDWidget.h>

AABPlayerController::AABPlayerController()
{
	//위젯 블루프린트 애셋에서 클래스 정보 바인딩(연결)
	static ConstructorHelpers::FClassFinder<UABHUDWidget> ABHUDWidgetRef(
		TEXT("/Game/ArenaBattle/UI/WBP_ABHUD.WBP_ABHUD_C")
	);
	
	//로드 성공시
	if (ABHUDWidgetRef.Succeeded())
	{
		ABHUDWidgetClass = ABHUDWidgetRef.Class;
	}
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//입력 설정.
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);

	//위젯 생성
	ABHUDWidget = CreateWidget<UABHUDWidget>(this, ABHUDWidgetClass);

	//문제가 없다면 화면에 추가
	if (nullptr != ABHUDWidget)
	{
		ABHUDWidget->AddToViewport();
	}

}
