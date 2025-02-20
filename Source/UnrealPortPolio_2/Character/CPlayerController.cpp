#include "CPlayerController.h"
#include "Global.h"
#include "AbilitySystemComponent.h"
#include "Character/CCharacter_Assassin.h"
#include "Character/CCharacter_Katana.h"
#include "DataAsset/DA_PlayerAttribute.h"
#include "GAS/AttributeSet/CPlayerAttributeSet.h"
#include "GAS/GA/GA_Tag.h"

ACPlayerController::ACPlayerController()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>("ASC");
	CheckNull(ASC);

	CHelpers::GetClass(&KatanaCharacter, "/Game/Character/Katana/BP_Katana");
	CheckNull(KatanaCharacter);

	CHelpers::GetAsset(&AttributeDataSet, "/Game/DataAsset/DA_PlayerAttribute");
	CheckNull(AttributeDataSet);
}

void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FGameplayAbilitySpec TagAbilitySpec(UGA_Tag::StaticClass());
	ASC->GiveAbility(TagAbilitySpec);

	SpawnPlayerClass.Add(Cast<ACCharacterBase>(GetPawn()));
	SpawnPlayerClass.Add(Cast<ACCharacterBase>(KatanaCharacter->GetDefaultObject()));

	for (const auto& Class : SpawnPlayerClass)
	{
		CLog::Print(Class->GetName());
	}
}

void ACPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// 여기서 데이터에셋 값 읽기
	CurrentPlayer = Cast<ACCharacterBase>(aPawn);

	//for (int32 i = 0; i < AttributeDataSet->Datas.Num(); i++)
	//{
	//	if (i == CurrentPlayer->index)
	//	{
	//		CurrentPlayer->GetPlayerAttributeSet()->SetBaseHealth(AttributeDataSet->Datas[i].BaseHealth);
	//		CurrentPlayer->GetPlayerAttributeSet()->SetBaseDamage(AttributeDataSet->Datas[i].BaseDamage);
	//		CurrentPlayer->GetPlayerAttributeSet()->SetBaseDefense(AttributeDataSet->Datas[i].BaseDefense);

	//		// Current값은 생각해야됨
	//	}
	//}

}

void ACPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

}

UAbilitySystemComponent* ACPlayerController::GetAbilitySystemComponent() const
{
	return ASC;
}

void ACPlayerController::Tag()
{
	FVector NewLocation = CurrentPlayer->GetActorLocation();

	CurrentPlayer->GetAbilitySystemComponent()->CancelAllAbilities();
	CurrentPlayer->SetActorLocation(FVector(0, 0, 1000));
	CurrentPlayer->UnPossessed();

	CurrentPlayer->Destroy();


	FTransform TF;
	TF.SetLocation(NewLocation);
	TF.SetRotation(FQuat(FRotator(0, -40, 0)));

	ACCharacter_Katana* Katana = GetWorld()->SpawnActor<ACCharacter_Katana>(KatanaCharacter, TF);
	CheckNull(Katana);

	OnPossess(Katana);
}
