from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='surfacing_script',
            namespace='surfacing_script',
            executable='surfacing_controller',
            name='surfacing_controller'
        ),
        Node(
            package='surfacing_script',
            namespace='surfacing_script',
            executable='talker',
            name='talker'
        ),
        Node(
            package='surfacing_script',
            namespace='surfacing_script',
            executable='geofloater',
            name='geofloater'
        )
    ])
