#include "CharacterTest.h"
#include <GameFramework/CharacterMovementComponent.h>

ACharacterTest::ACharacterTest()
{
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	bUseControllerRotationYaw = true;
}

void ACharacterTest::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ACharacterTest::MoveForward);
	PlayerInputComponent->BindAxis("Rotate", this, &ACharacterTest::Rotate);
}

void ACharacterTest::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	onMoveForward.Broadcast(_axis);
	//-> character movement -> max walk // GetCharacterMovement()
}

void ACharacterTest::Rotate(float _axis)
{
	AddControllerYawInput(_axis);
}

