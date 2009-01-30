/***************************************************************************
     Copyright          : (C) 2009 by Martin Sakmar
     e-mail             : martin.sakmar@gmail.com
 ***************************************************************************/

/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "bpmcounter.h"
#include "beatinfo.h"

#include <QDebug>

using namespace std;

BPMCounter::BPMCounter() {

}

BPMCounter::~BPMCounter() {

}

/**
 * @brief Correct BPM
 * if value is lower than min or greater than max
 * @return corrected BPM
 */
double BPMCounter::correctBPM(double dBPM) {
    //double min = getMinBPM();
    //double max = getMaxBPM();
    double min = 90;
    double max = 200;
    bool blimit = false;

    if ( dBPM < 1 ) return 0.;
    while ( dBPM > max ) dBPM /= 2.;
    while ( dBPM < min ) dBPM *= 2.;

    if (blimit && dBPM > max) {
        dBPM = 0.;
    }

    return dBPM;
}
