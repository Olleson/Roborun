// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/BatteryGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBatteryGameMode() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ABatteryGameMode_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ABatteryGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	DEFINE_FUNCTION(ABatteryGameMode::execGetDecayRate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetDecayRate();
		P_NATIVE_END;
	}
	void ABatteryGameMode::StaticRegisterNativesABatteryGameMode()
	{
		UClass* Class = ABatteryGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDecayRate", &ABatteryGameMode::execGetDecayRate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics
	{
		struct BatteryGameMode_eventGetDecayRate_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BatteryGameMode_eventGetDecayRate_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Power" },
		{ "Comment", "// Returns the current rate of decay (% of InitialPower per second)\n" },
		{ "ModuleRelativePath", "BatteryGameMode.h" },
		{ "ToolTip", "Returns the current rate of decay (% of InitialPower per second)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABatteryGameMode, nullptr, "GetDecayRate", nullptr, nullptr, sizeof(BatteryGameMode_eventGetDecayRate_Parms), Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABatteryGameMode_GetDecayRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABatteryGameMode_GetDecayRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABatteryGameMode_NoRegister()
	{
		return ABatteryGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ABatteryGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DecayRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DecayRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PowerDrainDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PowerDrainDelay;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABatteryGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABatteryGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABatteryGameMode_GetDecayRate, "GetDecayRate" }, // 1216860112
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABatteryGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BatteryGameMode.h" },
		{ "ModuleRelativePath", "BatteryGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_DecayRate_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "Power" },
		{ "Comment", "// The rate at which characters lose power (% of InitialPower per second)\n" },
		{ "ModuleRelativePath", "BatteryGameMode.h" },
		{ "ToolTip", "The rate at which characters lose power (% of InitialPower per second)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_DecayRate = { "DecayRate", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABatteryGameMode, DecayRate), METADATA_PARAMS(Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_DecayRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_DecayRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_PowerDrainDelay_MetaData[] = {
		{ "Category", "Power" },
		{ "Comment", "// How many times per second to update characters power and check game rules\n" },
		{ "ModuleRelativePath", "BatteryGameMode.h" },
		{ "ToolTip", "How many times per second to update characters power and check game rules" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_PowerDrainDelay = { "PowerDrainDelay", nullptr, (EPropertyFlags)0x0020080000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABatteryGameMode, PowerDrainDelay), METADATA_PARAMS(Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_PowerDrainDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_PowerDrainDelay_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABatteryGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_DecayRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryGameMode_Statics::NewProp_PowerDrainDelay,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABatteryGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABatteryGameMode_Statics::ClassParams = {
		&ABatteryGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABatteryGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABatteryGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABatteryGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABatteryGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABatteryGameMode, 4210465542);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<ABatteryGameMode>()
	{
		return ABatteryGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABatteryGameMode(Z_Construct_UClass_ABatteryGameMode, &ABatteryGameMode::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("ABatteryGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABatteryGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
