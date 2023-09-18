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

public:

    /// @brief Does the octant have available tranform data to spawn entities
    /// @param octantID 
    /// @return 
    bool is_octant_available(Vector3i octantID);

    /// @brief Returns a list of transforms, stored as a list of floats
    /// @param octantID 
    /// @return 
    Vector<float> get_octant_transforms(Vector3i octantID);

    /// @brief Frees the memory used by an octant transforms
    /// @param octantID 
    void clear_octant(Vector3i octantID);


    void store_transforms_data(PackedFloat32Array data);


    HashMap<Vector3i, Vector<float>> storage;
    
    //Vector<Vector<float>> chunksStorage;


    static void _bind_methods();


// --- PROPERTIES


};





} // namespace voxel


} // namespace zylann

#endif