/*
   This file is part of ArduinoIoTBearSSL.

   Copyright 2019 ARDUINO SA (http://www.arduino.cc/)

   This software is released under the GNU General Public License version 3,
   which covers the main part of ArduinoIoTBearSSL.
   The terms of this license can be found at:
   https://www.gnu.org/licenses/gpl-3.0.en.html

   You can be released from the requirements of the above licenses by purchasing
   a commercial license. Buying such a license is mandatory if you want to modify or
   otherwise use the software for commercial activities involving the Arduino
   software without disclosing the source code of your own applications. To purchase
   a commercial license, send an email to license@arduino.cc.

*/

#ifndef _BEAR_SSL_TRUST_ANCHOR_H_
#define _BEAR_SSL_TRUST_ANCHOR_H_

/******************************************************************************
 * INCLUDE
 ******************************************************************************/

#include "bearssl/bearssl_ssl.h"

/******************************************************************************
 * CONSTANTS
 ******************************************************************************/

// The following was created by running the BearSSL "brssl" tool in the
// extras/TrustAnchors directory:
//
//   brssl ta *.cer

//iot.arduino.cc:8885
static const unsigned char TA0_DN[] = {
  0x30, 0x45, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
  0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x0A,
  0x13, 0x0E, 0x41, 0x72, 0x64, 0x75, 0x69, 0x6E, 0x6F, 0x20, 0x4C, 0x4C,
  0x43, 0x20, 0x55, 0x53, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
  0x0B, 0x13, 0x02, 0x49, 0x54, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x13, 0x07, 0x41, 0x72, 0x64, 0x75, 0x69, 0x6E, 0x6F
};

static const unsigned char TA0_EC_Q[] = {
  0x04, 0xA1, 0xE1, 0x53, 0x6C, 0x35, 0x52, 0x1A, 0x33, 0x0D, 0xE8, 0x2B,
  0xAC, 0x5B, 0x12, 0xC1, 0x8F, 0x50, 0x37, 0xB3, 0x3E, 0x64, 0x9B, 0xA0,
  0xEE, 0x27, 0x02, 0x35, 0xC7, 0x8D, 0x5A, 0x10, 0x45, 0xD0, 0xCA, 0xF5,
  0x52, 0xEC, 0x97, 0xF2, 0x9A, 0xFF, 0x81, 0xC6, 0xE2, 0x79, 0x97, 0x3F,
  0xD3, 0x39, 0xC6, 0xD7, 0xA1, 0xCC, 0x6B, 0x61, 0x85, 0x70, 0xF6, 0x3B,
  0xAE, 0x62, 0x1D, 0x71, 0xC8
};

//iot.oniudra.cc:8885
static const unsigned char TA1_DN[] = {
  0x30, 0x45, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
  0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x0A,
  0x13, 0x0E, 0x41, 0x72, 0x64, 0x75, 0x69, 0x6E, 0x6F, 0x20, 0x4C, 0x4C,
  0x43, 0x20, 0x55, 0x53, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
  0x0B, 0x13, 0x02, 0x49, 0x54, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x13, 0x07, 0x41, 0x72, 0x64, 0x75, 0x69, 0x6E, 0x6F
};

static const unsigned char TA1_EC_Q[] = {
  0x04, 0x11, 0x70, 0x34, 0xE0, 0xC3, 0x3E, 0x00, 0xBD, 0x0B, 0x59, 0x03,
  0x98, 0xA0, 0x5B, 0x6B, 0x0B, 0x50, 0xDF, 0x51, 0x66, 0x4E, 0xE7, 0x40,
  0x5D, 0x5A, 0x46, 0x48, 0xE5, 0x30, 0x70, 0x35, 0xF9, 0xF3, 0x6C, 0xFC,
  0xDB, 0x47, 0x03, 0x78, 0x86, 0x82, 0xC0, 0xEC, 0x60, 0x86, 0x62, 0x3E,
  0xA7, 0xF0, 0xA9, 0x38, 0x7E, 0xB7, 0x7F, 0x91, 0x7A, 0x87, 0x6D, 0xC4,
  0xAE, 0xA6, 0x4C, 0x06, 0x48
};

static const br_x509_trust_anchor ArduinoIoTCloudTrustAnchor[2] = {
  {
    { (unsigned char *)TA0_DN, sizeof TA0_DN },
    BR_X509_TA_CA,
    {
      BR_KEYTYPE_EC,
      {
        .ec = {
          BR_EC_secp256r1,
          (unsigned char *)TA0_EC_Q, sizeof TA0_EC_Q,
        }
      }
    }
  },
  {
    { (unsigned char *)TA1_DN, sizeof TA1_DN },
    BR_X509_TA_CA,
    {
      BR_KEYTYPE_EC,
      {
        .ec = {
          BR_EC_secp256r1,
          (unsigned char *)TA1_EC_Q, sizeof TA1_EC_Q,
        }
      }
    }
  }
};

#define ArduinoIoTCloudTrustAnchor_NUM (2)

#endif /* _BEAR_SSL_TRUST_ANCHOR_H_ */
