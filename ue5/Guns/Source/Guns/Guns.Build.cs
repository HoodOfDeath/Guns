// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Guns : ModuleRules
{
	public Guns(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PrivateIncludePaths.AddRange(new string[]{ Name});
	}
}
