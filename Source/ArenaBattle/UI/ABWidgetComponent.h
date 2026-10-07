// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ABWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:
	//위젯 생성할 때 호출되는 함수.
	//위젯이 초기화된걸 보장하는 함수.->호출된걸 보장받을 수 있음.
	virtual void InitWidget() override;
	
};
