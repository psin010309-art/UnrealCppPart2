// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
//#include <Player/ABPlayerController.h>

AABGameMode::AABGameMode()
{
	//게임에서 사용할 클래스 타입 선언


	//블루프린트로부터 클래스 정보 로드.
	static ConstructorHelpers::FClassFinder<APawn>ThirdPersonClassRef(
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
	);

	if (ThirdPersonClassRef.Succeeded())
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}

	//플레이어 컨트롤러 클래스 선언
	//PlayerControllerClass = AABPlayerController::StaticClass();

	//cpp클래스도 애셋처럼 가져오기
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonPlayerController.BP_ThirdPersonPlayerController_C")
	);

	if (PlayerControllerClassRef.Succeeded())
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}

}
