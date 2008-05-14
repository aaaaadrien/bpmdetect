/***************************************************************************
     Copyright          : (C) 2007 by Martin Sakmar
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

#ifndef DLGTESTBPM_H
#define DLGTESTBPM_H

#include "trackfmod.h"
#include "dlgtestbpmdlg3.h"

/**
 * @brief Dialog for testing detected BPM
 */
class dlgTestBPM: public dlgTestBPMdlg {
   Q_OBJECT
public:
  dlgTestBPM( QString file, float dBPM,
           QWidget *parent = 0, const char *name = 0 );
  ~dlgTestBPM();

public slots:
  void setPos1();
  void setPos2();
  void setPos3();
  void setPos4();
  void setCustomPos( uint msec );
  /// Stop the track
  void stop();
  /// Set number of beats to loop
  void setNumBeats( const QString& );

private:
  float bpm;             ///< BPM to test
  FMOD_SYSTEM  *system;  ///< FMOD sound system
  FMOD_SOUND	 *sound;   ///< FMOD sound object
  FMOD_CHANNEL *channel; ///< FMOD channel object
};

#endif // DLGTESTBPM_H