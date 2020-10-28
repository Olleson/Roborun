// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/moveableBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodemoveableBox() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UmoveableBox_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UmoveableBox();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentReference();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void UmoveableBox::StaticRegisterNativesUmoveableBox()
	{
	}
	UClass* Z_Construct_UClass_UmoveableBox_NoRegister()
	{
		return UmoveableBox::StaticClass();
	}
	struct Z_Construct_UClass_UmoveableBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_movementvecktor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_movementvecktor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EndPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StartPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ender_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ender;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Endpoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Endpoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelfActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelfActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UmoveableBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "moveableBox.h" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_TargetPosition_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_TargetPosition = { "TargetPosition", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, TargetPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_TargetPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_TargetPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementSpeed_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementSpeed = { "MovementSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, MovementSpeed), METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementDistance_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementDistance = { "MovementDistance", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, MovementDistance), METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_movementvecktor_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_movementvecktor = { "movementvecktor", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, movementvecktor), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_movementvecktor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_movementvecktor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_EndPosition_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_EndPosition = { "EndPosition", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, EndPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_EndPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_EndPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_StartPosition_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_StartPosition = { "StartPosition", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, StartPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_StartPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_StartPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_ender_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_ender = { "ender", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, ender), Z_Construct_UScriptStruct_FComponentReference, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_ender_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_ender_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_Endpoint_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_Endpoint = { "Endpoint", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, Endpoint), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_Endpoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_Endpoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmoveableBox_Statics::NewProp_SelfActor_MetaData[] = {
		{ "Category", "moveableBox" },
		{ "ModuleRelativePath", "moveableBox.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UmoveableBox_Statics::NewProp_SelfActor = { "SelfActor", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UmoveableBox, SelfActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::NewProp_SelfActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::NewProp_SelfActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UmoveableBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_TargetPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_MovementDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_movementvecktor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_EndPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_StartPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_ender,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_Endpoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UmoveableBox_Statics::NewProp_SelfActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UmoveableBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UmoveableBox>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UmoveableBox_Statics::ClassParams = {
		&UmoveableBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UmoveableBox_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UmoveableBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UmoveableBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UmoveableBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UmoveableBox_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UmoveableBox, 1988323105);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<UmoveableBox>()
	{
		return UmoveableBox::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UmoveableBox(Z_Construct_UClass_UmoveableBox, &UmoveableBox::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("UmoveableBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UmoveableBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
