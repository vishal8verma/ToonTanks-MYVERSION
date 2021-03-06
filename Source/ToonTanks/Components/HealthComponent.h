// Copyright©2021 vAhirwar Technology.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:

UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category="Default Health!",meta=(AllowPrivateAccess=true));
	float DefaultHealth =100.f;

	float Health =0.f;

	class ATankGameModeBase* GameModeRef =nullptr;


public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
UFUNCTION()
	void TakeDamage(AActor* DamageActor,float Damage,const UDamageType*DamageType,AController* InstigatedBy,AActor* DamageCauser);

		
};
