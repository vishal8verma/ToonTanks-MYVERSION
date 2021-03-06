// Copyright©2021 vAhirwar Technology.All rights reserved.


#include "HealthComponent.h"
#include"Kismet/GameplayStatics.h"
#include"ToonTanks/GameModeBase/TankGameModeBase.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health =DefaultHealth;
	GameModeRef =Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::TakeDamage);


	// ...
	
}

void UHealthComponent::TakeDamage(AActor* DamageActor,float Damage,const UDamageType*DamageType,AController* InstigatedBy,AActor* DamageCauser) 
{
	if(Damage==0||Damage<=0)
	{
		return;
	}
	Health =FMath::Clamp(Health-Damage,0.f,DefaultHealth);
	if(Health<=0)
	{
		if(GameModeRef)
		{
			GameModeRef->ActorDead(GetOwner());
		}else
		{
			UE_LOG(LogTemp,Error,TEXT("Health Component Don't Have Any Valid Reference To Game Mode!"));
			return;
		};
		
	};
}


