AES PP Decoder

Decode PP alarm packets from hex string to human readable format.

Compiles with G++ under Linux 6.14 & Windows 11.
      
        g++ pp_decoder.cpp -o pp_decoder


Usage:

      ./pp_decoder "PPff00300000001100014500008300005E4A1E0180001FFE0A30302030313435203138204531313520303020433136300D00BAA5"
      Calculated Checksum:   47781, Hex Challenge:  baa5, Checksums match? true
              To ID: 00
            From ID: 011
         Link Layer: 0
          Origin ID: 145
            Dest ID: 00
        Packet Type: 5e
      Sequence Num: 74
    Payload length: 30
      Payload Data: ��
      00 0145 18 E115 00 C160
