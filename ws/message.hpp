#ifndef WS_MESSAGE_HPP
#define WS_MESSAGE_HPP

#include <vector>

namespace ws {

class message {
public:
    enum class opcode {
        /* non-control frames */
        continuation = 0x00,
        text = 0x01,
        binary = 0x02,
        /* control frames */
        connection_close = 0x08,
        ping = 0x09,
        pong = 0x0a
    };

    message(opcode op, std::vector<unsigned char> payload) :
        opcode_(op), payload_(std::move(payload)) { }

    opcode get_opcode() const {
        return opcode_;
    }

    void set_opcode(opcode op) {
        opcode_ = op;
    }

    const std::vector<unsigned char> &get_payload() const {
        return payload_;
    }
private:
    opcode opcode_;
    std::vector<unsigned char> payload_;
};

} /* namespace ws */

#endif /* WS_MESSAGE_HPP */
