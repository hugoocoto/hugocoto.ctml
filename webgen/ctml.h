#define DOCTYPE(type) "<!DOCTYPE " #type ">"

// Generic html TAG macro
// clang-format off
#define tag(name, content, ...) \
        "<" #name __VA_OPT__(" " asstr(__VA_ARGS__)) ">" \
        content \
        "</" #name ">"
// clang-format on

// Specific tags
#define html(content, ...) tag(html, content, __VA_ARGS__)
#define div(content, ...) tag(div, content, __VA_ARGS__)
#define p(content, ...) tag(p, content, __VA_ARGS__)
#define head(content, ...) tag(head, content, __VA_ARGS__)
#define body(content, ...) tag(body, content, __VA_ARGS__)
#define a(content, ...) tag(a, content, __VA_ARGS__)
#define h1(content, ...) tag(h1, content, __VA_ARGS__)
#define h2(content, ...) tag(h2, content, __VA_ARGS__)
#define h3(content, ...) tag(h3, content, __VA_ARGS__)
#define h4(content, ...) tag(h4, content, __VA_ARGS__)
#define h5(content, ...) tag(h5, content, __VA_ARGS__)


#define title(t) "<title>" t "</title>"

// avoid collision with posix link()
#define linktag(rel, href) "<link rel=\"" rel "\" href=\"" href "\">"
#define style(s) linktag("stylesheet", s)
#define icon(s) linktag("icon", s)

#define meta(name, content) "<meta name=\"" name "\" content=\"" content "\">"
#define description(s) meta("description", s)

#define ul(content, ...) tag(ul, content, __VA_ARGS__)
#define liref(text, href, ...) "<li" __VA_OPT__(" " asstr(__VA_ARGS__)) "><a href=" #href ">" text "</a></li>"
#define li(text, ...) "<li" __VA_OPT__(" " asstr(__VA_ARGS__)) ">" text "</li>"

#define img(alt, src, ...) "<img" __VA_OPT__(" " asstr(__VA_ARGS__) " ") "src=" src " alt=" alt ">"

// Convert __VA_ARGS__ to space separated strings
#define asstr(a, ...) #a __VA_OPT__(" " asstr1(__VA_ARGS__))
#define asstr1(a, ...) #a __VA_OPT__(" " asstr2(__VA_ARGS__))
#define asstr2(a, ...) #a __VA_OPT__(" " asstr3(__VA_ARGS__))
#define asstr3(a, ...) #a __VA_OPT__(" " asstr4(__VA_ARGS__))
#define asstr4(a, ...) #a __VA_OPT__(" " asstr5(__VA_ARGS__))
#define asstr5(a, ...) #a __VA_OPT__(" ")

#define lit(a) #a
