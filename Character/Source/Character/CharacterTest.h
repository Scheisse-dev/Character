#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "CharacterTest.generated.h"

UCLASS()
class CHARACTER_API ACharacterTest : public ACharacter
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);

		UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnMoveForward onMoveForward;

public:
	ACharacterTest();
	FORCEINLINE FOnMoveForward& OnMoveForward() {
		return onMoveForward;
	}
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
};
