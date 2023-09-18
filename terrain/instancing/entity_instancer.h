#ifndef ENTITY_INSTANCER_H
#define ENTITY_INSTANCER_H


#include "../../constants/voxel_constants.h"
#include "../../streams/instance_data.h"
#include "../../util/fixed_array.h"
#include "../../util/godot/classes/node_3d.h"
#include "../../util/godot/direct_multimesh_instance.h"
#include "../../util/math/box3i.h"
#include "../../util/memory.h"
#include "generate_instances_block_task.h"
#include "voxel_instance_generator.h"
#include "voxel_instance_library.h"
#include "voxel_instance_library_multimesh_item.h"


namespace zylann
{
    

namespace voxel {

class EntityInstancer : public Node3D {
    GDCLASS(EntityInstancer, Node3D)

    
// --- Constructor & Destructor

    EntityInstancer();
    ~EntityInstancer();

// --- PROPERTIES


};





} // namespace voxel


} // namespace zylann

#endif