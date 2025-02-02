

#include "RainActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARainActor::ARainActor()
{
 	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->SetSimulatePhysics(true);
	// Enable generate overlap events for the root component
	Mesh->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ARainActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetEnableGravity(true);
	
}

// Called every frame
void ARainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z < -1000.0f)
	{
		Destroy();
	}

}

void ARainActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->GetName() == "MyCube" )

	{
		UE_LOG(LogTemp, Warning, TEXT("destroy"));
		
		Destroy();
	}
}

