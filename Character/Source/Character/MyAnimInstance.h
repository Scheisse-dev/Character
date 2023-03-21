// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTest.h"
#include "MyAnimInstance.generated.h"

UCLASS()
class CHARACTER_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
		UPROPERTY()
		TObjectPtr<ACharacterTest> chara = nullptr;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float speed = 0;
private:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float _deltaSeconds) override;
	float GetSpeed() const;
	void SetSpeed(float _speed);
};
