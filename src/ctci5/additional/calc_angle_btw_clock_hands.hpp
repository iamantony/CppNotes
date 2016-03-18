#ifndef CALC_ANGLE_BTW_CLOCK_HANDS_HPP_
#define CALC_ANGLE_BTW_CLOCK_HANDS_HPP_

#include <limits>

// Given a time, calculate the angle between the hour and minute hands

double CalcAngleBtwClockHands(const double& t_hour, const double& t_minute)
{
    const double CIRCLE = 360.0;
    const double MAX_MINUTES = 60.0;
    const double MAX_HOURS = 12.0;

    if (t_hour < 0.0 || MAX_HOURS < t_hour ||
            t_minute < 0.0 || MAX_MINUTES < t_minute)
    {
        return 0.0;
    }

    auto areEqual = [](const double& left, const double& right)
    {
        return std::fabs(left - right) <=
                std::numeric_limits<double>::epsilon();
    };

    double hour = t_hour;
    double minute = t_minute;
    if (areEqual(hour, MAX_HOURS))
    {
        hour = 0.0;
    }

    if (areEqual(minute, MAX_MINUTES))
    {
        minute = 0.0;
    }

    double anglePerMinute = CIRCLE / MAX_MINUTES;
    double minuteAngle = anglePerMinute * minute;

    double anglePerHour = CIRCLE / MAX_HOURS;
    double mainHourAngle = anglePerHour * hour;
    double additionalHourAngle = minuteAngle * (1 / MAX_HOURS);
    double hourAngle = mainHourAngle + additionalHourAngle;

    double angle = std::abs(hourAngle - minuteAngle);
    return std::min(CIRCLE - angle, angle);
}

#endif /* CALC_ANGLE_BTW_CLOCK_HANDS_HPP_ */
