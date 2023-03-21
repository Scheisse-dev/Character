// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeBeginPlay()
{
	chara = Cast<ACharacterTest>(TryGetPawnOwner());
	if (!chara)
		return;
	chara->OnMoveForward().AddDynamic(this, &UMyAnimInstance::SetSpeed);

}

void UMyAnimInstance::NativeUpdateAnimation(float _deltaSeconds)
{
	speed = GetSpeed();
}


float UMyAnimInstance::GetSpeed() const
{
	const APawn* _target = TryGetPawnOwner();
	if (!_target)
		return 0;
	return _target->GetVelocity().GetSafeNormal().Size();
}

void UMyAnimInstance::SetSpeed(float _speed)
{
	speed = _speed;
}
