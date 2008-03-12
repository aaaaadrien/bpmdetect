/***************************************************************************
     Copyright          : (C) 2008 by Martin Sakmar
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

#ifndef TRACK_H
#define TRACK_H

#include <string>

typedef struct taginfo_s {
  std::string BPM;
  std::string Artist;
  std::string Title;
} taginfo_t;

enum TrackType {
  TYPE_UNKNOWN   = 0,
  TYPE_MPEG      = 1,
  TYPE_WAV       = 2,
  TYPE_OGGVORBIS = 3,
  TYPE_FLAC      = 4,
};

/**
*/
class Track {
public:
  Track(std::string filename);
  ~Track();

  /// Convert std::string to BPM
  static double str2bpm( std::string sBPM );
  /// Convert BPM to std::string using selected format
  static std::string bpm2str( double dBPM, std::string format = "0.00");
  static void setMinBPM(double dMin);
  static void setMaxBPM(double dMax);
  static double getMinBPM();
  static double getMaxBPM();

  double detectBPM();
  /// Save BPM to tag formatted using format
  void saveBPM( std::string format = "0.00" );
  /// Print BPM to stdout formatted using format
  void printBPM( std::string format = "0.00" );
  /// Return detected BPM
  double getBPM() const;
  /// Set the filename
  void setFilename( std::string filename );
  /// Return the filename
  std::string getFilename() const;
  /// Return BPM as std::string formatted using format
  std::string strBPM( std::string format = "0.00" );
  bool isValid() const;

protected:
  /// Correct detected BPM
  double correctBPM();
  void setValid( bool bValid );
  void setBPM( double dBPM );

  TrackType getTrackType();
  /// Read ID3v2 tag (mp3 file)
  taginfo_t getTagInfoMPEG();
  /// Read ID3v2 tag (wav file)
  taginfo_t getTagInfoWAV();

// #ifdef HAVE_ID3LIB
  void saveMPEG_ID3( std::string sBPM, std::string filename );
  void saveWAV_ID3( std::string sBPM, std::string filename );
//#endif // HAVE_ID3LIB
#ifdef HAVE_TAGLIB
  void saveMPEG_TAG( std::string sBPM, std::string filename );
  void saveWAV_TAG( std::string sBPM, std::string filename );
  void saveOGG_TAG( std::string sBPM, std::string filename );
  void saveFLAC_TAG( std::string sBPM, std::string filename );
#endif // HAVE_TAGLIB

private:
  std::string m_sFilename;
  double m_dBPM;
  bool m_bValid;

};

#endif