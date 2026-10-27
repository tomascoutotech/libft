#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;

	dlen = 0;
	while (dlen < dstsize && dst[dlen])
		dlen++;
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	return (dlen + ft_strlcpy(dst + dlen, src, dstsize - dlen));
}
