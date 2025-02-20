#include "GAS/GE/GE_CoolDown.h"

UGE_CoolDown::UGE_CoolDown()
{
	DurationPolicy = EGameplayEffectDurationType::HasDuration;

	FScalableFloat DurationValue;
	DurationValue.SetValue(3.0f);

	DurationMagnitude = DurationValue;

	/*FGameplayModifierInfo Modifier;
	Modifier.Attribute = FGameplayAttribute(FindFieldChecked<FProperty>(
		UCWeaponAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCWeaponAttributeSet, CurrentDamage)
	));

	Modifier.ModifierOp = EGameplayModOp::Additive;
	Modifier.ModifierMagnitude = FGameplayEffectModifierMagnitude(10.f);*/

	// Modifiers.Add(Modifier);

	//FScalableFloat DurationValue;
	//DurationValue.SetValue(3.0f);

	//DurationMagnitude = DurationValue;

	//Period = 0.0f;
	//bIsBlockingOtherAbilities = true;

	//// ��Ÿ���� ���� �� �ִϸ��̼� �Ǵ� ĳ���� �ɷ� �ߵ� �����ϵ��� ����
	//FGameplayModifierInfo CooldownModifier;
	//CooldownModifier.Attribute = UAbilitySystemComponent::GetCooldownAttribute();  // ���� �Ӽ�
	//CooldownModifier.ModifierOp = EGameplayModOp::Additive;
	//CooldownModifier.Magnitude = FGameplayEffectModifierMagnitude(0.0f);  // ��Ÿ���� ���� �� �ɷ� �ߵ� ����

	//Modifiers.Add(CooldownModifier);


}
