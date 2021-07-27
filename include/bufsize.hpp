// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef BUFSIZE_BUFSIZE_HPP
#define BUFSIZE_BUFSIZE_HPP

extern "C" {
    #include <sys/ioctl.h>
    #include <unistd.h>
}

class __bufsize {
public:
    unsigned columns = 0, rows = 0;
};

namespace bufsize {
    __bufsize init() noexcept {
        __bufsize val;

        #ifdef TIOCGSIZE
            struct ttysize size;

            if(ioctl(STDOUT_FILENO, TIOCGSIZE, &size) == 0) {
                val.rows    = size.ts_lines;
                val.columns = size.ts_cols ;
            }
        #else
            struct winsize size;

            if(ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == 0) {
                val.rows    = size.ws_row;
                val.columns = size.ws_col;
            }
        #endif

        return val;
    }
}

#endif // BUFSIZE_BUFSIZE_HPP
