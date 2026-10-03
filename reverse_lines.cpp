#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

static const size_t BUF_SIZE = 1 << 16;

int main(int argc, char** argv) {
    if (argc != 3) {
        std::fprintf(stderr, "usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    std::FILE* in = std::fopen(argv[1], "rb");
    if (!in) { std::perror(argv[1]); return 1; }

    std::FILE* out = std::fopen(argv[2], "wb");
    if (!out) { std::perror(argv[2]); std::fclose(in); return 1; }

    std::setvbuf(in, nullptr, _IONBF, 0);
    std::setvbuf(out, nullptr, _IONBF, 0);

    std::vector<char> buf(BUF_SIZE);
    size_t held = 0;

    for (;;) {
        size_t got = std::fread(buf.data() + held, 1, buf.size() - held, in);
        if (got == 0) break;
        size_t filled = held + got;

        size_t scan = 0;
        for (;;) {
            char* nl = static_cast<char*>(
                std::memchr(buf.data() + scan, '\n', filled - scan));
            if (!nl) break;
            size_t end = static_cast<size_t>(nl - buf.data());
            std::reverse(buf.data() + scan, buf.data() + end);
            scan = end + 1;
        }

        if (scan != 0) std::fwrite(buf.data(), 1, scan, out);

        held = filled - scan;
        if (held != 0) std::memmove(buf.data(), buf.data() + scan, held);

        if (held == buf.size()) buf.resize(buf.size() * 2);
    }

    if (held != 0) {
        std::reverse(buf.data(), buf.data() + held);
        std::fwrite(buf.data(), 1, held, out);
    }

    bool read_failed = std::ferror(in) != 0;
    std::fclose(in);
    bool write_failed = std::ferror(out) != 0;
    if (std::fclose(out) != 0) write_failed = true;

    if (read_failed)  { std::fprintf(stderr, "error reading %s\n", argv[1]);  return 1; }
    if (write_failed) { std::fprintf(stderr, "error writing %s\n", argv[2]); return 1; }
    return 0;
}
