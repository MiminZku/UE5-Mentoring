// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5Mentoring : ModuleRules
{
	public UE5Mentoring(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
