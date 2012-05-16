/*********************************************************************/
// dar - disk archive - a backup/restoration program
// Copyright (C) 2002-2052 Denis Corbin
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
// to contact the author : dar.linux@free.fr
/*********************************************************************/
// $Id: filtre.hpp,v 1.13 2004/11/07 18:21:38 edrusb Rel $
//
/*********************************************************************/

    /// \file filtre.hpp
    /// \brief here is all the core routines for the operations
    /// \ingroup Private

#ifndef FILTRE_HPP
#define FILTRE_HPP

#include "../my_config.h"
#include <vector>
#include "mask.hpp"
#include "compressor.hpp"
#include "catalogue.hpp"
#include "path.hpp"
#include "statistics.hpp"

namespace libdar
{

    extern void filtre_restore(user_interaction & dialog,
			       const mask &filtre,
                               const mask & subtree,
                               catalogue & cat,
                               bool detruire,
                               const path & fs_racine,
                               bool fs_allow_overwrite,
                               bool fs_warn_overwrite,
                               bool info_details,
                               statistics & st,
                               bool only_if_more_recent,
                               bool restore_ea_root,
                               bool restore_ea_user,
                               bool flat,
                               bool ignore_owner,
			       bool warn_remove_no_match,
                               const infinint & hourshift,
			       bool empty);

    extern void filtre_sauvegarde(user_interaction & dialog,
				  const mask &filtre,
                                  const mask &subtree,
                                  compressor *stockage,
                                  catalogue & cat,
                                  catalogue &ref,
                                  const path & fs_racine,
                                  bool info_details,
                                  statistics & st,
                                  bool make_empty_dir,
                                  bool save_ea_root,
                                  bool save_ea_user,
                                  const mask &compr_mask,
                                  const infinint & min_compr_size,
                                  bool nodump,
                                  const infinint & hourshift,
				  bool alter_time,
				  bool same_fs,
				  bool ignore_owner);

    extern void filtre_difference(user_interaction & dialog,
				  const mask &filtre,
                                  const mask &subtree,
                                  catalogue & cat,
                                  const path & fs_racine,
                                  bool info_details, statistics & st,
                                  bool check_ea_root,
                                  bool check_ea_user,
				  bool alter_time,
				  bool ignore_owner);

    extern void filtre_test(user_interaction & dialog,
			    const mask &filtre,
                            const mask &subtree,
                            catalogue & cat,
                            bool info_details,
                            statistics & st);

    extern void filtre_isolate(user_interaction & dialog,
			       catalogue & cat,
                               catalogue & ref,
                               bool info_details);

} // end of namespace

#endif
