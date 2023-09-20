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
public :
    EntityInstancer();
    ~EntityInstancer();


    /// @brief Does the octant have available tranform data to spawn entities
    /// @param octantID 
    /// @return 
    bool is_octant_available(Vector3i octantID);

    /// @brief Returns a list of transforms, stored as a list of floats
    /// @param octantID 
    /// @return 
    Vector<float> get_octant_transforms(Vector3i octantID);

    /// @brief Get the pointer to the transform array
    /// @param octantID 
    /// @return 
    int64_t get_octant_transforms_direct(int64_t id);

    /// @brief Get the size of the transform array
    /// @return 
    int64_t get_octant_transform_array_len(int64_t id);


    // Might not be thread safe. Be careful
    bool is_layer_initialized(int64_t id);

    Transform3D get_trs_at(int64_t trs_id, int64_t arrayID);


    /// @brief Frees the memory used by an octant transforms
    /// @param octantID 
    void clear_octant(Vector3i octantID);

    /// @brief Called by VoxelInstancer instead of multimesh
    /// @param data 
    void store_transforms_data(Span<const Transform3f> data);


    Vector<Transform3D> data[3] = {};
    bool initialized[3] = {false, false, false};

    HashMap<Vector3i, Vector<Transform3D>> storage;
    
    //Vector<Vector<float>> chunksStorage;

    Mutex mut;

    static void _bind_methods();

    


// --- PROPERTIES


};





} // namespace voxel


} // namespace zylann

#endif