#include "MonolithAnimationModule.h"
#include "MonolithAnimationActions.h"
#include "MonolithToolRegistry.h"
#include "MonolithJsonUtils.h"
#include "MonolithSettings.h"

#define LOCTEXT_NAMESPACE "FMonolithAnimationModule"

void FMonolithAnimationModule::StartupModule()
{
	if (!GetDefault<UMonolithSettings>()->bEnableAnimation) return;

	FMonolithAnimationActions::RegisterActions(FMonolithToolRegistry::Get());
	UE_LOG(LogMonolith, Log, TEXT("Monolith — Animation module loaded (23 actions)"));
}

void FMonolithAnimationModule::ShutdownModule()
{
	FMonolithToolRegistry::Get().UnregisterNamespace(TEXT("animation"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMonolithAnimationModule, MonolithAnimation)
