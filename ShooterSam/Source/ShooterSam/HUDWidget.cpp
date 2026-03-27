// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"

void UHUDWidget::SetHealthBarPersent(float percent)
{
	if (percent >= 0.0f && percent <= 1.0f)
	{
		HealthBar->SetPercent(percent);
	}
}
