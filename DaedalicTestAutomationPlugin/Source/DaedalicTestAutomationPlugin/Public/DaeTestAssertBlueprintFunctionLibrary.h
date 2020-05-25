#pragma once

#include "DaeTestComparisonMethod.h"
#include <CoreMinimal.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include <UObject/TextProperty.h>
#include "DaeTestAssertBlueprintFunctionLibrary.generated.h"

class UImage;
class URichTextBlock;
class UTextBlock;
class UUserWidget;

class ADaeTestTriggerBox;

/** Utility functions for asserting state in automated tests. */
UCLASS()
class DAEDALICTESTAUTOMATIONPLUGIN_API UDaeTestAssertBlueprintFunctionLibrary
    : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Finishes the current test as failure. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertFail(const FString& What, UObject* Context = nullptr);

    /** Expects the specified value to be true. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertTrue(bool bValue, const FString& What, UObject* Context = nullptr);

    /** Expects the specified value to be false. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertFalse(bool bValue, const FString& What, UObject* Context = nullptr);

    /** Expects the specified object to be valid. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertValid(UObject* Object, const FString& What, UObject* Context = nullptr);

    /** Expects the specified object not to be valid. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertInvalid(UObject* Object, const FString& What, UObject* Context = nullptr);

    /** Expects the specified trigger box to be triggered. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertWasTriggered(ADaeTestTriggerBox* TestTriggerBox, UObject* Context = nullptr);

    /** Expects the specified trigger box not to be triggered. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertWasNotTriggered(ADaeTestTriggerBox* TestTriggerBox,
                                      UObject* Context = nullptr);

    /** Expects the specified values to be equal. */
    UFUNCTION(BlueprintCallable, CustomThunk,
              meta = (CustomStructureParam = "Actual,Expected", HidePin = "WorldContext",
                      DefaultToSelf = "WorldContext", DisplayName = "Assert Equal"))
    static void AssertEqual(const int32 Actual, const int32 Expected, const FString& What,
                            UObject* WorldContext = nullptr);

    /** Expects the specified values not to be equal. */
    UFUNCTION(BlueprintCallable, CustomThunk,
              meta = (CustomStructureParam = "Actual,Unexpected", HidePin = "WorldContext",
                      DefaultToSelf = "WorldContext", DisplayName = "Assert Not Equal"))
    static void AssertNotEqual(const int32 Actual, const int32 Unexpected, const FString& What,
                               UObject* WorldContext = nullptr);

    /** Compares the specified bytes for order. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Compare (Byte)"))
    static void AssertCompareByte(uint8 First, EDaeTestComparisonMethod ShouldBe, uint8 Second,
                                  const FString& What, UObject* Context = nullptr);

    /** Compares the specified 32-bit integers for order. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Compare (Integer)"))
    static void AssertCompareInt32(int32 First, EDaeTestComparisonMethod ShouldBe, int32 Second,
                                   const FString& What, UObject* Context = nullptr);

    /** Compares the specified 64-bit integers for order. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Compare (Integer64)"))
    static void AssertCompareInt64(int64 First, EDaeTestComparisonMethod ShouldBe, int64 Second,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects the specified floats to be (nearly) equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Equal (Float)", AdvancedDisplay = "Tolerance"))
    static void AssertEqualFloat(float Actual, float Expected, const FString& What,
                                 const float Tolerance = 0.0001f,
                                 UObject* Context = nullptr);

    /** Expects the specified floats not to be equal. */
    UFUNCTION(BlueprintCallable,
              meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Not Equal (Float)", AdvancedDisplay = "Tolerance"))
    static void AssertNotEqualFloat(float Actual, float Unexpected, const FString& What,
                                    const float Tolerance = 0.0001f, UObject* Context = nullptr);

    /** Compares the specified floats for order. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Compare (Float)"))
    static void AssertCompareFloat(float First, EDaeTestComparisonMethod ShouldBe, float Second,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects the specified names to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Equal (Name)"))
    static void AssertEqualName(const FName& Actual, const FName& Expected, bool bIgnoreCase,
                                const FString& What, UObject* Context = nullptr);

    /** Expects the specified names not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not Equal (Name)"))
    static void AssertNotEqualName(const FName& Actual, const FName& Unexpected, bool bIgnoreCase,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects the specified strings to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Equal (String)"))
    static void AssertEqualString(const FString& Actual, const FString& Expected, bool bIgnoreCase,
                                  const FString& What, UObject* Context = nullptr);

    /** Expects the specified strings not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not Equal (String)"))
    static void AssertNotEqualString(const FString& Actual, const FString& Unexpected,
                                     bool bIgnoreCase, const FString& What,
                                     UObject* Context = nullptr);

    /** Expects the specified texts to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Equal (Text)"))
    static void AssertEqualText(const FText& Actual, const FText& Expected, bool bIgnoreCase,
                                const FString& What, UObject* Context = nullptr);

    /** Expects the specified texts not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not Equal (Text)"))
    static void AssertNotEqualText(const FText& Actual, const FText& Unexpected, bool bIgnoreCase,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects the specified vectors to be (nearly) equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Equal (Vector)", AdvancedDisplay = "Tolerance"))
    static void AssertEqualVector(const FVector& Actual, const FVector& Expected,
                                  const FString& What, const float Tolerance = 0.0001f,
                                  UObject* Context = nullptr);

    /** Expects the specified vectors not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Not Equal (Vector)", AdvancedDisplay = "Tolerance"))
    static void AssertNotEqualVector(const FVector& Actual, const FVector& Unexpected,
                                     const FString& What, const float Tolerance = 0.0001f,
                                     UObject* Context = nullptr);

    /** Expects the specified rotators to be (nearly) equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Equal (Rotator)", AdvancedDisplay = "Tolerance"))
    static void AssertEqualRotator(const FRotator& Actual, const FRotator& Expected,
                                   const FString& What, const float Tolerance = 0.0001f,
                                   UObject* Context = nullptr);

    /** Expects the specified rotators not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Not Equal (Rotator)", AdvancedDisplay = "Tolerance"))
    static void AssertNotEqualRotator(const FRotator& Actual, const FRotator& Unexpected,
                                      const FString& What, const float Tolerance = 0.0001f,
                                      UObject* Context = nullptr);

    /** Expects the specified transforms to be (nearly) equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Equal (Transform)", AdvancedDisplay = "Tolerance"))
    static void AssertEqualTransform(const FTransform& Actual, const FTransform& Expected,
                                     const FString& What, const float Tolerance = 0.0001f,
                                     UObject* Context = nullptr);

    /** Expects the specified transforms not to be equal. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                      DisplayName = "Assert Not Equal (Transform)", AdvancedDisplay = "Tolerance"))
    static void AssertNotEqualTransform(const FTransform& Actual, const FTransform& Unexpected,
                                        const FString& What, const float Tolerance = 0.0001f,
                                        UObject* Context = nullptr);

    /** Expects Value to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert In Range (Byte)"))
    static void AssertInRangeByte(uint8 Value, uint8 MinInclusive, uint8 MaxInclusive,
                                  const FString& What, UObject* Context = nullptr);

    /** Expects Value not to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not In Range (Byte)"))
    static void AssertNotInRangeByte(uint8 Value, uint8 MinInclusive, uint8 MaxInclusive,
                                     const FString& What, UObject* Context = nullptr);

    /** Expects Value to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert In Range (Integer)"))
    static void AssertInRangeInt32(int32 Value, int32 MinInclusive, int32 MaxInclusive,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects Value not to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not In Range (Integer)"))
    static void AssertNotInRangeInt32(int32 Value, int32 MinInclusive, int32 MaxInclusive,
                                      const FString& What, UObject* Context = nullptr);

    /** Expects Value to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert In Range (Integer64)"))
    static void AssertInRangeInt64(int64 Value, int64 MinInclusive, int64 MaxInclusive,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects Value not to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not In Range (Integer64)"))
    static void AssertNotInRangeInt64(int64 Value, int64 MinInclusive, int64 MaxInclusive,
                                      const FString& What, UObject* Context = nullptr);

    /** Expects Value to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert In Range (Float)"))
    static void AssertInRangeFloat(float Value, float MinInclusive, float MaxInclusive,
                                   const FString& What, UObject* Context = nullptr);

    /** Expects Value not to be between MinInclusive and MaxInclusive. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context",
                                         DisplayName = "Assert Not In Range (Float)"))
    static void AssertNotInRangeFloat(float Value, float MinInclusive, float MaxInclusive,
                                      const FString& What, UObject* Context = nullptr);

    /** Expects the specified widget to be valid and visible (e.g. added to viewport, not hidden or collapsed). */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertWidgetIsVisible(UUserWidget* Widget, const FString& What,
                                      UObject* Context = nullptr);

    /** Expects the specified text not to be empty. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertTextIsSet(UTextBlock* TextBlock, const FString& What,
                                UObject* Context = nullptr);

    /** Expects the specified rich text not to be empty. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertRichTextIsSet(URichTextBlock* RichTextBlock, const FString& What,
                                    UObject* Context = nullptr);

    /** Expects the specified image to be set up to use a texture or material. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "Context", DefaultToSelf = "Context"))
    static void AssertImageIsSet(UImage* Image, const FString& What, UObject* Context = nullptr);

private:
    static const FString ErrorMessageFormatEqual;
    static const FString ErrorMessageFormatNotEqual;
    static const FString ErrorMessageFormatLessThan;
    static const FString ErrorMessageFormatLessThanOrEqualTo;
    static const FString ErrorMessageFormatGreaterThan;
    static const FString ErrorMessageFormatGreaterThanOrEqualTo;
    static const FString ErrorMessageFormatInRange;
    static const FString ErrorMessageFormatNotInRange;

    static void OnTestFailed(UObject* Context, const FString& Message);

    static void GenericAssertEqual(void* Actual, const FProperty* ActualProp, void* Expected,
                                   const FProperty* ExpectedProp, const FString& What,
                                   UObject* Context = nullptr);
    DECLARE_FUNCTION(execAssertEqual)
    {
        // Retrieve the first value
        Stack.MostRecentProperty = nullptr;
        Stack.StepCompiledIn<FProperty>(NULL);
        void* ActualAddr = Stack.MostRecentPropertyAddress;
        FProperty* ActualProperty = Stack.MostRecentProperty;
        // Retrieve the second value
        Stack.MostRecentProperty = nullptr;
        Stack.StepCompiledIn<FProperty>(NULL);
        void* ExpectedAddr = Stack.MostRecentPropertyAddress;
        FProperty* ExpectedProperty = Stack.MostRecentProperty;

        P_GET_PROPERTY(FStrProperty, What);
        P_GET_PROPERTY(FObjectProperty, WorldContext);

        P_FINISH;
        P_NATIVE_BEGIN;
        GenericAssertEqual(ActualAddr, ActualProperty, ExpectedAddr, ExpectedProperty, What,
                           WorldContext);
        P_NATIVE_END;
    }

    static void GenericAssertNotEqual(void* Actual, const FProperty* ActualProp, void* Unexpected,
                                      const FProperty* UnexpectedProp, const FString& What,
                                      UObject* Context = nullptr);
    DECLARE_FUNCTION(execAssertNotEqual)
    {
        // Retrieve the first value
        Stack.MostRecentProperty = nullptr;
        Stack.StepCompiledIn<FProperty>(NULL);
        void* ActualAddr = Stack.MostRecentPropertyAddress;
        FProperty* ActualProperty = Stack.MostRecentProperty;
        // Retrieve the second value
        Stack.MostRecentProperty = nullptr;
        Stack.StepCompiledIn<FProperty>(NULL);
        void* UnexpectedAddr = Stack.MostRecentPropertyAddress;
        FProperty* UnexpectedProperty = Stack.MostRecentProperty;

        P_GET_PROPERTY(FStrProperty, What);
        P_GET_PROPERTY(FObjectProperty, WorldContext);

        P_FINISH;
        P_NATIVE_BEGIN;
        GenericAssertNotEqual(ActualAddr, ActualProperty, UnexpectedAddr, UnexpectedProperty, What,
                              WorldContext);
        P_NATIVE_END;
    }

    template<typename T>
    static void AssertCompare(UObject* Context, const FString& What, T First,
                              EDaeTestComparisonMethod ShouldBe, T Second)
    {
        bool bFulfilled = false;

        switch (ShouldBe)
        {
            case EDaeTestComparisonMethod::LessThan:
                bFulfilled = First < Second;
                break;

            case EDaeTestComparisonMethod::LessThanOrEqualTo:
                bFulfilled = First <= Second;
                break;

            case EDaeTestComparisonMethod::GreaterThanOrEqualTo:
                bFulfilled = First >= Second;
                break;

            case EDaeTestComparisonMethod::GreaterThan:
                bFulfilled = First > Second;
                break;
        }

        if (bFulfilled)
        {
            return;
        }

        FString FormatString;

        switch (ShouldBe)
        {
            case EDaeTestComparisonMethod::LessThan:
                FormatString = ErrorMessageFormatLessThan;
                break;

            case EDaeTestComparisonMethod::LessThanOrEqualTo:
                FormatString = ErrorMessageFormatLessThanOrEqualTo;
                break;

            case EDaeTestComparisonMethod::GreaterThanOrEqualTo:
                FormatString = ErrorMessageFormatGreaterThanOrEqualTo;
                break;

            case EDaeTestComparisonMethod::GreaterThan:
                FormatString = ErrorMessageFormatGreaterThan;
                break;
        }

        FString Message = FString::Format(*FormatString, {What, First, Second});
        OnTestFailed(Context, Message);
    }
};
