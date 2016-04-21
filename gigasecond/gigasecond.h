#ifndef GIGASECOND_H
#define GIGASECOND_H
#include <boost/date_time/gregorian/gregorian.hpp>

namespace gigasecond {

boost::gregorian::date advance(const boost::gregorian::date& input_date) {
    return boost::gregorian::days(1000000000/(24 * 60 * 60)) + input_date;
}

}

#endif // GIGASECOND_H