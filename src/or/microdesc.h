/* Copyright (c) 2001 Matej Pfajfar.
 * Copyright (c) 2001-2004, Roger Dingledine.
 * Copyright (c) 2004-2006, Roger Dingledine, Nick Mathewson.
 * Copyright (c) 2007-2010, The Tor Project, Inc. */
/* See LICENSE for licensing information */

/**
 * \file microdesc.h
 * \brief Header file for microdesc.c.
 **/

#ifndef _TOR_MICRODESC_H
#define _TOR_MICRODESC_H

microdesc_cache_t *get_microdesc_cache(void);

smartlist_t *microdescs_add_to_cache(microdesc_cache_t *cache,
                        const char *s, const char *eos, saved_location_t where,
                        int no_save, time_t listed_at,
                        smartlist_t *requested_digests256);
smartlist_t *microdescs_add_list_to_cache(microdesc_cache_t *cache,
                        smartlist_t *descriptors, saved_location_t where,
                        int no_save);

void microdesc_cache_clean(microdesc_cache_t *cache);
int microdesc_cache_rebuild(microdesc_cache_t *cache);
int microdesc_cache_reload(microdesc_cache_t *cache);
void microdesc_cache_clear(microdesc_cache_t *cache);

microdesc_t *microdesc_cache_lookup_by_digest256(microdesc_cache_t *cache,
                                                 const char *d);

size_t microdesc_average_size(microdesc_cache_t *cache);

smartlist_t *microdesc_list_missing_digest256(networkstatus_t *ns,
                                              microdesc_cache_t *cache,
                                              int downloadable_only,
                                              digestmap_t *skip);

void microdesc_free(microdesc_t *md);
void microdesc_free_all(void);

void update_microdesc_downloads(time_t now);
void update_microdescs_from_networkstatus(time_t now);

#endif

