// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/MovingPlatform.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovingPlatform() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UMovingPlatform_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UMovingPlatform();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(UMovingPlatform::execMovePlatform)
	{
		P_GET_STRUCT(FVector,Z_Param_targetPosition);
		P_GET_STRUCT(FVector,Z_Param_CurrentPosition);
		P_GET_STRUCT(FVector,Z_Param_EndPosition);
		P_GET_STRUCT(FVector,Z_Param_StartPosition);
		P_GET_PROPERTY(FFloatProperty,Z_Param_MovementSpeed);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetPositionOut);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_MovementVectorOut);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->MovePlatform(Z_Param_targetPosition,Z_Param_CurrentPosition,Z_Param_EndPosition,Z_Param_StartPosition,Z_Param_MovementSpeed,Z_Param_Out_TargetPositionOut,Z_Param_Out_MovementVectorOut);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMovingPlatform::execSetMovementVector)
	{
		P_GET_STRUCT(FVector,Z_Param_CurrentLocation);
		P_GET_STRUCT(FVector,Z_Param_TargetLocation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_MovementSpeed);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_MovementVector);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMovementVector(Z_Param_CurrentLocation,Z_Param_TargetLocation,Z_Param_MovementSpeed,Z_Param_Out_MovementVector);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMovingPlatform::execsetSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_traveltime);
		P_GET_PROPERTY(FFloatProperty,Z_Param_distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->setSpeed(Z_Param_traveltime,Z_Param_distance);
		P_NATIVE_END;
	}
	void UMovingPlatform::StaticRegisterNativesUMovingPlatform()
	{
		UClass* Class = UMovingPlatform::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MovePlatform", &UMovingPlatform::execMovePlatform },
			{ "SetMovementVector", &UMovingPlatform::execSetMovementVector },
			{ "setSpeed", &UMovingPlatform::execsetSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics
	{
		struct MovingPlatform_eventMovePlatform_Parms
		{
			FVector targetPosition;
			FVector CurrentPosition;
			FVector EndPosition;
			FVector StartPosition;
			float MovementSpeed;
			FVector TargetPositionOut;
			FVector MovementVectorOut;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MovementVectorOut;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetPositionOut;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StartPosition;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EndPosition;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CurrentPosition;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_targetPosition;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MovingPlatform_eventMovePlatform_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MovingPlatform_eventMovePlatform_Parms), &Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_MovementVectorOut = { "MovementVectorOut", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, MovementVectorOut), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_TargetPositionOut = { "TargetPositionOut", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, TargetPositionOut), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_MovementSpeed = { "MovementSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, MovementSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_StartPosition = { "StartPosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, StartPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_EndPosition = { "EndPosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, EndPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_CurrentPosition = { "CurrentPosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, CurrentPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_targetPosition = { "targetPosition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventMovePlatform_Parms, targetPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_MovementVectorOut,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_TargetPositionOut,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_MovementSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_StartPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_EndPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_CurrentPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::NewProp_targetPosition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovingPlatform, nullptr, "MovePlatform", nullptr, nullptr, sizeof(MovingPlatform_eventMovePlatform_Parms), Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovingPlatform_MovePlatform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMovingPlatform_MovePlatform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics
	{
		struct MovingPlatform_eventSetMovementVector_Parms
		{
			FVector CurrentLocation;
			FVector TargetLocation;
			float MovementSpeed;
			FVector MovementVector;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MovementVector;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CurrentLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_MovementVector = { "MovementVector", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventSetMovementVector_Parms, MovementVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_MovementSpeed = { "MovementSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventSetMovementVector_Parms, MovementSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventSetMovementVector_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_CurrentLocation = { "CurrentLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventSetMovementVector_Parms, CurrentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_MovementVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_MovementSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_TargetLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::NewProp_CurrentLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovingPlatform, nullptr, "SetMovementVector", nullptr, nullptr, sizeof(MovingPlatform_eventSetMovementVector_Parms), Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovingPlatform_SetMovementVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMovingPlatform_SetMovementVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics
	{
		struct MovingPlatform_eventsetSpeed_Parms
		{
			float traveltime;
			float distance;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_distance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_traveltime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventsetSpeed_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_distance = { "distance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventsetSpeed_Parms, distance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_traveltime = { "traveltime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MovingPlatform_eventsetSpeed_Parms, traveltime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_distance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::NewProp_traveltime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovingPlatform, nullptr, "setSpeed", nullptr, nullptr, sizeof(MovingPlatform_eventsetSpeed_Parms), Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovingPlatform_setSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMovingPlatform_setSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMovingPlatform_NoRegister()
	{
		return UMovingPlatform::StaticClass();
	}
	struct Z_Construct_UClass_UMovingPlatform_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovingPlatform_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMovingPlatform_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMovingPlatform_MovePlatform, "MovePlatform" }, // 3999872721
		{ &Z_Construct_UFunction_UMovingPlatform_SetMovementVector, "SetMovementVector" }, // 1534168684
		{ &Z_Construct_UFunction_UMovingPlatform_setSpeed, "setSpeed" }, // 299157167
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovingPlatform_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MovingPlatform.h" },
		{ "ModuleRelativePath", "MovingPlatform.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovingPlatform_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovingPlatform>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovingPlatform_Statics::ClassParams = {
		&UMovingPlatform::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovingPlatform_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovingPlatform_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovingPlatform()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovingPlatform_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovingPlatform, 3262898270);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<UMovingPlatform>()
	{
		return UMovingPlatform::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovingPlatform(Z_Construct_UClass_UMovingPlatform, &UMovingPlatform::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("UMovingPlatform"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovingPlatform);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
