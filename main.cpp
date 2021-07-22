/*
Author: Braeden Kilburn
Date: 07/22/2021
Description:    Using the "1 in 60 rule", 
                we will calculate track error and correction 
                error for an airplane in flight. These calculations
                are not completely accurate (rounding and precision);
                however, since even a skilled pilot cannot manually fly 
                with better than about 2° accuracy, and winds are constantly 
                varying, the rule remains useful for most realistic situations.
*/
#include <iostream>
#include <iomanip>

using namespace std;

double getTrackError(double milesOffTrack, double milesFlown)
{
    return (milesOffTrack * 60) / milesFlown;
}

double getCorrectionAngle(double milesOffTrack, double milesRemaining)
{
    return (milesOffTrack * 60) / milesRemaining;
}

int getTotalCorrection(double trackError, double correctionAngle)
{
    return trackError + correctionAngle;
}

int getCorrectedHeading(int currentHeading, double totalCorrection)
{
    return currentHeading - totalCorrection;
}

int main()
{
    double milesOffTrack = 0;
    double milesFlown = 0;
    double milesRemaining = 0;
    int currentHeading = 0;

    cout << "How many miles (NM) off track are you? ";
    cin >> milesOffTrack;

    cout << "How many miles (NM) have you flown so far? ";
    cin >> milesFlown;

    cout << "How many miles (NM) do you have remaining? ";
    cin >> milesRemaining;

    cout << "What's your current heading? ";
    cin >> currentHeading;

    double trackError = getTrackError(milesOffTrack, milesFlown);
    double correctionAngle = getCorrectionAngle(milesOffTrack, milesRemaining);
    double totalCorrection = getTotalCorrection(trackError, correctionAngle);
    int suggestedHeading = getCorrectedHeading(currentHeading, totalCorrection);

    cout << fixed << setprecision(0);
    cout << "\nTrack Error: " << trackError << " degrees" << endl;
    cout << "Correction Angle: " << correctionAngle << " degrees" << endl;
    cout << "Total Correction: " << totalCorrection << " degrees" << endl;

    cout << "\nSuggested Heading: " << suggestedHeading << " degrees" << endl;

    return 0;
}