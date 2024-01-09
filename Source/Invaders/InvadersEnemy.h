// Copy Right

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvadersEnemy.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UNiagaraSystem;

UCLASS()
class INVADERS_API AInvadersEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInvadersEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly) TObjectPtr<UBoxComponent> EnemyCollision;
	UPROPERTY(EditDefaultsOnly) TObjectPtr <UStaticMeshComponent> EnemyMesh;
	UPROPERTY(EditDefaultsOnly) TObjectPtr <UNiagaraSystem> NiagaraSystem;
	UPROPERTY(EditDefaultsOnly) TObjectPtr <USoundBase> BlastSound;

	UFUNCTION() void EnemyOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void SpawnExplosionFX() const;
	UFUNCTION() void SpawnSound() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
