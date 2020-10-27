// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class HideNSneakUnreal : ModuleRules
{
	public HideNSneakUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
<<<<<<< HEAD
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
=======
		PrivateDependencyModuleNames.Add("OnlineSubsystem");
>>>>>>> 42f0643de269f3f43e79bd4fa738a91aec78cd07

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
