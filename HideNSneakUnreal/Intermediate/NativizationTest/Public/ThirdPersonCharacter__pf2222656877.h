#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
class UCameraComponent;
class USpringArmComponent;
class UPrimitiveComponent;
class AActor;
#include "ThirdPersonCharacter__pf2222656877.generated.h"
UCLASS(config=Game, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/ThirdPersonBP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C", OverrideNativeName="ThirdPersonCharacter_C"))
class AThirdPersonCharacter_C__pf2222656877 : public ACharacter
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="MyCharacter", OverrideNativeName="FollowCamera"))
	UCameraComponent* bpv__FollowCamera__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="MyCharacter", OverrideNativeName="CameraBoom"))
	USpringArmComponent* bpv__CameraBoom__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Base Turn Rate", Category="Default", OverrideNativeName="BaseTurnRate"))
	float bpv__BaseTurnRate__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Base Look Up Rate", Category="Default", OverrideNativeName="BaseLookUpRate"))
	float bpv__BaseLookUpRate__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Owned Tags", Category="Default", MultiLine="true", OverrideNativeName="OwnedTags"))
	FGameplayTag bpv__OwnedTags__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="New Var 0", Category="Default", MultiLine="true", OverrideNativeName="NewVar_0"))
	FGameplayTag bpv__NewVar_0__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Hider Tag", Category="Default", MultiLine="true", OverrideNativeName="HiderTag"))
	FName bpv__HiderTag__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Seeker Tag", Category="Default", MultiLine="true", OverrideNativeName="SeekerTag"))
	FName bpv__SeekerTag__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputTouchEvent_FingerIndex"))
	TEnumAsByte<ETouchIndex::Type> b0l__K2Node_InputTouchEvent_FingerIndex__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputTouchEvent_Location"))
	FVector b0l__K2Node_InputTouchEvent_Location__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_MakeArray_Array"))
	TArray<FName> b0l__K2Node_MakeArray_Array__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="Temp_byte_Variable"))
	TEnumAsByte<ETouchIndex::Type> b0l__Temp_byte_Variable__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="Temp_struct_Variable"))
	FVector b0l__Temp_struct_Variable__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputActionEvent_Key_1"))
	FKey b0l__K2Node_InputActionEvent_Key_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputActionEvent_Key"))
	FKey b0l__K2Node_InputActionEvent_Key__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="Temp_struct_Variable_1"))
	FKey b0l__Temp_struct_Variable_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue_5"))
	float b0l__K2Node_InputAxisEvent_AxisValue_5__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue_4"))
	float b0l__K2Node_InputAxisEvent_AxisValue_4__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue_3"))
	float b0l__K2Node_InputAxisEvent_AxisValue_3__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue_2"))
	float b0l__K2Node_InputAxisEvent_AxisValue_2__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Roll"))
	float b0l__CallFunc_BreakRotator_Roll__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Pitch"))
	float b0l__CallFunc_BreakRotator_Pitch__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Yaw"))
	float b0l__CallFunc_BreakRotator_Yaw__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue_1"))
	float b0l__K2Node_InputAxisEvent_AxisValue_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue"))
	float b0l__K2Node_InputAxisEvent_AxisValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_MyComp"))
	UPrimitiveComponent* b0l__K2Node_Event_MyComp__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_Other"))
	AActor* b0l__K2Node_Event_Other__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_OtherComp"))
	UPrimitiveComponent* b0l__K2Node_Event_OtherComp__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_bSelfMoved"))
	bool b0l__K2Node_Event_bSelfMoved__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_HitLocation"))
	FVector b0l__K2Node_Event_HitLocation__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_HitNormal"))
	FVector b0l__K2Node_Event_HitNormal__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_NormalImpulse"))
	FVector b0l__K2Node_Event_NormalImpulse__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_Hit"))
	FHitResult b0l__K2Node_Event_Hit__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_GetAllActorsWithTag_OutActors"))
	TArray<AActor*> b0l__CallFunc_GetAllActorsWithTag_OutActors__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputTouchEvent_FingerIndex_1"))
	TEnumAsByte<ETouchIndex::Type> b0l__K2Node_InputTouchEvent_FingerIndex_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputTouchEvent_Location_1"))
	FVector b0l__K2Node_InputTouchEvent_Location_1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_Array_Get_Item"))
	AActor* b0l__CallFunc_Array_Get_Item__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_MakeArray_Array_1"))
	TArray<FName> b0l__K2Node_MakeArray_Array_1__pf;
	AThirdPersonCharacter_C__pf2222656877(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_1(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_2(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_3(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_4(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_5(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_6(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_7(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_8(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_9(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_10(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_ThirdPersonCharacter__pf_11(int32 bpp__EntryPoint__pf);
	UFUNCTION(meta=(Comment="/** Event when play begins for this actor. */", DisplayName="BeginPlay", ToolTip="Event when play begins for this actor.", CppFromBpEvent, OverrideNativeName="ReceiveBeginPlay"))
	virtual void bpf__ReceiveBeginPlay__pf();
	UFUNCTION(meta=(Category="Collision", Comment="/** \t * Event when this actor bumps into a blocking object, or blocks another actor that bumps into it.\t * This could happen due to things like Character movement, using Set Location with \'sweep\' enabled, or physics simulation.\t * For events when objects overlap (e.g. walking into a trigger) see the \'Overlap\' event.\t *\t * @note For collisions during physics simulation to generate hit events, \'Simulation Generates Hit Events\' must be enabled.\t * @note When receiving a hit from another object\'s movement (bSelfMoved is false), the directions of \'Hit.Normal\' and \'Hit.ImpactNormal\'\t * will be adjusted to indicate force from the other object against this object.\t * @note NormalImpulse will be filled in for physics-simulating bodies, but will be zero for swept-component blocking collisions.\t */", DisplayName="Hit", ToolTip="Event when this actor bumps into a blocking object, or blocks another actor that bumps into it.This could happen due to things like Character movement, using Set Location with \'sweep\' enabled, or physics simulation.For events when objects overlap (e.g. walking into a trigger) see the \'Overlap\' event.@note For collisions during physics simulation to generate hit events, \'Simulation Generates Hit Events\' must be enabled.@note When receiving a hit from another object\'s movement (bSelfMoved is false), the directions of \'Hit.Normal\' and \'Hit.ImpactNormal\'will be adjusted to indicate force from the other object against this object.@note NormalImpulse will be filled in for physics-simulating bodies, but will be zero for swept-component blocking collisions.", CppFromBpEvent, OverrideNativeName="ReceiveHit"))
	virtual void bpf__ReceiveHit__pf(UPrimitiveComponent* bpp__MyComp__pf, AActor* bpp__Other__pf, UPrimitiveComponent* bpp__OtherComp__pf, bool bpp__bSelfMoved__pf, FVector bpp__HitLocation__pf, FVector bpp__HitNormal__pf, FVector bpp__NormalImpulse__pf, FHitResult const& bpp__Hit__pf__const);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_LookUpRate_K2Node_InputAxisEvent_53"))
	virtual void bpf__InpAxisEvt_LookUpRate_K2Node_InputAxisEvent_53__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_TurnRate_K2Node_InputAxisEvent_38"))
	virtual void bpf__InpAxisEvt_TurnRate_K2Node_InputAxisEvent_38__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_LookUp_K2Node_InputAxisEvent_40"))
	virtual void bpf__InpAxisEvt_LookUp_K2Node_InputAxisEvent_40__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_MoveRight_K2Node_InputAxisEvent_90"))
	virtual void bpf__InpAxisEvt_MoveRight_K2Node_InputAxisEvent_90__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_MoveForward_K2Node_InputAxisEvent_79"))
	virtual void bpf__InpAxisEvt_MoveForward_K2Node_InputAxisEvent_79__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_Turn_K2Node_InputAxisEvent_47"))
	virtual void bpf__InpAxisEvt_Turn_K2Node_InputAxisEvent_47__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_Jump_K2Node_InputActionEvent_0"))
	virtual void bpf__InpActEvt_Jump_K2Node_InputActionEvent_0__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_Jump_K2Node_InputActionEvent_1"))
	virtual void bpf__InpActEvt_Jump_K2Node_InputActionEvent_1__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpTchEvt_Pressed"))
	virtual void bpf__InpTchEvt_Pressed__pf(ETouchIndex::Type bpp__FingerIndex__pf, FVector bpp__Location__pf);
	UFUNCTION(meta=(OverrideNativeName="InpTchEvt_Released"))
	virtual void bpf__InpTchEvt_Released__pf(ETouchIndex::Type bpp__FingerIndex__pf, FVector bpp__Location__pf);
public:
};
